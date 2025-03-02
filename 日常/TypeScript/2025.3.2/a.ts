// function sum(x:number, ...numbers: number[]): number{
// 	console.log("x", x);
// 	return numbers.reduce((total, n) => total + n, 0);
// }
// let x = sum(1, 2, 3, 4);

// console.log(x);

const obj = {
	value: 10,
	add: function (a: number, b: number): number{
		return this.value + a + b;
	},
};

const res = obj.add.apply({value: 100}, [10, 20]);
console.log(res); // 130