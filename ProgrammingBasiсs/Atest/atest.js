'use strict';

const add = (...argsX) => {
    let x = 0;
    argsX.forEach(arg => { x += arg });

    const f = (...argsY) => {
        let y = 0;
        argsY.forEach(arg => { y += arg });

        return add(x, y);
    }
    
    f.map = fn => fn(x);
    return f;
};

const a = add(2, 8)(3)(5, 1)(7);
a.map(console.log);
add(2, 8)(3)(5, 1)(7)(1).map(console.log);
