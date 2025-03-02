"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const V8Flags = [
    '--max-old-space-size=4096', '--max-semi-space-size=16', '--stack-size=65536', '--reclaim-unused-memory',
    '--gc-interval=100', '--expose-gc', '--gc-global', '--optimize-for-speed',
    '--always-opt', '--max-inlined-source-size=600', '--max-inlined-bytecode-size=600', '--turbo-inline-js-wasm-calls',
    '--turbo', '--turbo-optimizer', '--force-optimization', '--no-lazy',
    '--no-lazy-inner-functions', '--optimize-for-size', '--initial-heap-size=64', '--max-heap-size=192',
    '--use-strict', '--predictable', '--single-threaded-gc', '--no-inline-new',
    '--opt', '--no-lazy-deserialization', '--no-browser-globals', '--turbo-inline-array-builtins',
    '--fast-math', '--fuzzing', '--minor-mc', '--incremental-marking',
    '--concurrent-recompilation', '--stress-compaction', '--experimental-flush-embedded-blob-icache', '--experimental-value-unavailable'
];
if (V8Flags.length > 0) {
    process.execArgv.push('--v8-options=' + V8Flags.join(' '));
}
var fs = require("fs");
var IO = {
    _buf: Buffer.alloc(1 << 14),
    _bufPos: 0,
    _bufLen: 0,
    _ensure: function () {
        if (this._bufPos === this._bufLen) {
            this._bufPos = 0;
            this._bufLen = fs.readSync(0, this._buf, 0, this._buf.length, null);
        }
    },
    _isws: function (ch) {
        return ch === 32 || ch === 9 || ch === 10 || ch === 13;
    },
    _islf: function (ch) {
        return ch === 10 || ch === 13;
    },
    _peekChar: function () {
        this._ensure();
        return this._bufPos === this._bufLen ? 0 : this._buf[this._bufPos];
    },
    _skipWs: function () {
        while (this._isws(this._peekChar()))
            this._bufPos++;
    },
    _readUntil: function (stop) {
        this._ensure();
        if (this._bufPos === this._bufLen)
            throw new Error("eof");
        var start = this._bufPos;
        var before = null;
        for (;;) {
            if (this._bufPos === this._bufLen) {
                var len = this._bufPos - start, preLen = (before ? before.length : 0);
                var nbuf = Buffer.alloc(len + preLen);
                if (before)
                    before.copy(nbuf);
                before = nbuf;
                this._buf.copy(before, preLen, start);
                this._ensure();
                start = this._bufPos;
            }
            if (this._bufPos === this._bufLen || stop(this._buf[this._bufPos]))
                break;
            this._bufPos++;
        }
        if (!before)
            return this._buf.toString("utf8", start, this._bufPos);
        var after = this._buf.slice(start, this._bufPos);
        var res = Buffer.alloc(before.length + after.length);
        before.copy(res);
        after.copy(res, before.length);
        return res.toString();
    },
    nextToken: function () {
        this._skipWs();
        return this._readUntil(this._isws);
    },
    nextLine: function () {
        var line = this._readUntil(this._islf);
        if (this._peekChar() === 13)
            this._bufPos++;
        if (this._peekChar() === 10)
            this._bufPos++;
        return line;
    },
    nextNumber: function () {
        return +this.nextToken();
    },
    nextInt: function () {
        return this.nextToken() | 0;
    }
};
function swap(a, b) {
    return [b, a];
}
let t = IO.nextNumber();
while (t--) {
    solve();
}
function solve() {
    let n = IO.nextNumber();
    let s = IO.nextNumber();
    let t = IO.nextNumber();
    let dep = Array.from({ length: n + 1 }, () => []);
    let v = Array.from({ length: n + 1 }, () => []);
    let ans = [];
    for (let i = 1; i < n; i++) {
        let x = IO.nextInt();
        let y = IO.nextNumber();
        v[x].push(y);
        v[y].push(x);
    }
    let stack = [[t, 0, -1]];
    while (stack.length > 0) {
        let [x, d, fa] = stack.pop();
        dep[d].push(x);
        for (let y of v[x]) {
            if (y === fa)
                continue;
            stack.push([y, d + 1, x]);
        }
    }
    // function dfs(x:number, d:number, fa:number):void {
    //     dep[d].push(x);
    //     for (let y of v[x]) {
    //         if (y === fa)
    //             continue;
    //         dfs(y, d + 1, x);
    //     }
    // }
    // dfs(t, 0, -1);
    for (let i = n - 1; i >= 0; i--)
        for (let x of dep[i])
            ans.push(x);
    console.log(ans.join(" "));
}
/*
4
1 1 1
2 1 2
1 2
3 2 2
1 2
2 3
6 1 4
1 2
1 3
4 5
5 6
1 4

*/ 
