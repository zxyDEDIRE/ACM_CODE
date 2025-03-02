"use strict";
// function sum(x:number, ...numbers: number[]): number{
// 	console.log("x", x);
// 	return numbers.reduce((total, n) => total + n, 0);
// }
// let x = sum(1, 2, 3, 4);
Object.defineProperty(exports, "__esModule", { value: true });
// console.log(x);
const obj = {
    value: 10,
    add: function (a, b) {
        return this.value + a + b;
    },
};
const res = obj.add.apply({ value: 100 }, [10, 20]);
console.log(res); // 130
