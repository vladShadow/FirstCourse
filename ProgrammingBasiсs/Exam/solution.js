'use strict'

const inputArray = require('./array.js');

let newObj = {};
const goThroughObject = function(obj, keyName) {
    if (!keyName) newObj = {};
    newObj[keyName] = {};
    
    Object.keys(obj).forEach(key => {
        if (obj[key].constructor === Object) {
            const nextKeyName = keyName ? keyName + '.' + key : key;
            goThroughObject(obj[key], nextKeyName);
        }
        else {
        newObj[keyName][key] = obj[key];
        }
    });
    
    return newObj;
}

const goThroughObjectFromRoot = arg => goThroughObject(arg, "");
    
const outputArray = inputArray.map(goThroughObjectFromRoot);

const log = console.log.bind(outputArray);
log(outputArray);



const fn = a => b => callback => callback(a + b);
for (let i = 0; i <= 10; i++) {
    const f = fn(i);
    for (let j=0; j <= 10; j++) {
        f(j)(console.log);
    }
}



