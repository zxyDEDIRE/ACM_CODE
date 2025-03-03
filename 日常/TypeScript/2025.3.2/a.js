"use strict";
// function sum(x:number, ...numbers: number[]): number{
// 	console.log("x", x);
// 	return numbers.reduce((total, n) => total + n, 0);
// }
// let x = sum(1, 2, 3, 4);
Object.defineProperty(exports, "__esModule", { value: true });
// console.log(x);
// const obj = {
// 	value: 10,
// 	add: function (a: number, b: number): number{
// 		return this.value + a + b;
// 	},
// };
// const res = obj.add.apply({value: 100}, [10, 20]);
// console.log(res); // 130
// let x = {
// 	a() {
// 		console.log(this);
// 	}
// }
// x.a();
function* func() {
    let a = 0;
    let b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}
let a = func();
console.log(a.next());
console.log(a.next());
console.log(a.next());
console.log(a.next());
