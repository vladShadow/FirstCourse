
#include <iostream>
#include <map>
#include <vector>
#include <random>
using namespace std;


class Town{
public:
    string name_;
    Town(string name){
        name_ = name;
    }
    bool operator< (const Town& userObj) const
    {
        if(userObj.name_.size() < this->name_.size())
            return true;
    }

};

class Node{
public:
    Town * t;
    Node(Town *t_){
        t = t_;
    }
    map<Town*, int> neighbors_;
    void add(Town *t, int length){
        this->neighbors_.insert(pair<Town*,int>(t,length));
    }
    int get_l(Town *t){
        if(this->neighbors_.find(t) != this->neighbors_.end()) {
            return this->neighbors_[t];
        }
    }
};

int index_find(vector<Node>, Town *);

class Greedy{
private:
    int path_ = 0;
    vector<Town*> Greedy_algo(Town * t1, Town * t2, vector<Node> graph){
        vector<Town*> path;
        Town * curr_t, * min_t;
        curr_t = t1;
        path.push_back(t1);
        while (curr_t != t2){
            Node * curr_n = &graph[index_find(graph,curr_t)];
            auto it = curr_n->neighbors_.begin();
            min_t = it->first;
            for(; it != curr_n->neighbors_.end(); it++ ) {
                if(graph[index_find(graph,it->first)].get_l(t2) < graph[index_find(graph,min_t)].get_l(t2)){
                    min_t = it->first;
                }
            }
            path_ += graph[index_find(graph, curr_t)].get_l(min_t);
            curr_t = min_t;
            path.push_back(min_t);
        }
        return path;
    }
public:
    Greedy(){}
    void greedy(Town *t1, Town *t2, vector<Node> graph){

        vector<Town *> path_greedy = Greedy_algo(t1, t2, graph);
        cout << "\n[Greedy] " << t1->name_ << "-" << t2->name_ << ". Distance: " << calculate_path() << ". Path: ";
        for (auto it = path_greedy.begin(); it != path_greedy.end(); ) {
            cout << (*it)->name_;
            if (++it != path_greedy.end()) cout << "->";
        }
    }
    int calculate_path(){
        return path_;
    }
};

class AStar{
private:
    int path_ = 0;
    vector<Town*> AStar_algo(Town * t1, Town * t2, vector<Node> graph) {
        vector<Town *> path;
        Town *curr_t, *min_t;
        curr_t = t1;
        path.push_back(t1);
        while (curr_t != t2) {
            Node *curr_n = &graph[index_find(graph, curr_t)];
            auto it = curr_n->neighbors_.begin();
            it++;
            min_t = it->first;
            for (; it != curr_n->neighbors_.end(); it++) {
                int l = (graph[index_find(graph, it->first)].get_l(t2) + curr_n->get_l(it->first));
                int r = (graph[index_find(graph, min_t)].get_l(t2) + curr_n->get_l(min_t));
                if (l <= r) {
                    min_t = it->first;
                }
            }
            path_ += graph[index_find(graph, curr_t)].get_l(min_t);
            curr_t = min_t;
            path.push_back(min_t);
        }
        return path;
    }
public:
    AStar(){}
    void astar(Town *t1, Town *t2, vector<Node> graph){
        vector<Town *> path_astar = AStar_algo(t1, t2, graph);
        cout << "\n[A*] " << t1->name_ << "-" << t2->name_ << ". Distance: " << calculate_path() << ". Path: ";
        for (auto it = path_astar.begin(); it != path_astar.end(); ) {
            cout << (*it)->name_;
            if (++it != path_astar.end()) cout << "->";
        }
    }
    int calculate_path(){
        return path_;
    }
};



int main() {
    Town towns[] = {Town("Cordoba"),
                    Town("Rosario"),
                    Town("Santa Fe"),
                    Town("Mendoza"),
                    Town("Buenos Aires"),
                    Town("La Plata"),
                    Town("Mar del Plata"),
                    Town("Necochea"),
                    Town("Bahia Blanca"),
                    Town("Santa Rosa"),
                    Town("San Carlos de Bariloche"),
                    Town("Trelew"),
                    Town("San Miguel de Tacuman"),
                    Town("Salta"),
                    Town("Villa Maria")};

    vector<Node> graph;
    for (int i = 0; i < 15; i++) {
        graph.emplace_back(Node(&towns[i]));
        graph[i].add(&towns[i], 0);
        for (int j = 1; j < 15; j++) {
            graph[i].add(&towns[j], rand() % (j * 10) + (j - 1) * 10 + 1);
        }
    }

    AStar a;
    Greedy g;
    a.astar(&towns[0],&towns[7], graph);
    g.greedy(&towns[0],&towns[7], graph);
    return 0;
}

int index_find(vector<Node> graph, Town * curr){
    for (int i = 0; i < graph.size(); i++){
        if (graph[i].t == curr){
            return i;
        }
    }

}