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
        
        _isws: function (ch:any) {
                return ch === 32 || ch === 9 || ch === 10 || ch === 13;
        },
        
        _islf: function (ch:any) {
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
        
        _readUntil: function (stop:any) {
                this._ensure();
                if (this._bufPos === this._bufLen)
                        throw new Error("eof");
                var start = this._bufPos;
                var before = null;
                for (;;) {
                        if (this._bufPos === this._bufLen) {
                                var len = this._bufPos - start,
                                        preLen = (before ? before.length : 0);
                                var nbuf = Buffer.alloc(len + preLen);
                                if (before)
                                        before.copy(nbuf);
                                before = nbuf;
                                this._buf.copy(before, preLen, start);
                                this._ensure();
                                start = this._bufPos;
                        }
                        if (this._bufPos === this._bufLen || stop(this._buf[this._bufPos])) break;
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
        
        nextToken: function ():any {
                this._skipWs();
                return this._readUntil(this._isws);
        },
        
        nextLine: function () {
                var line = this._readUntil(this._islf);
                if (this._peekChar() === 13) this._bufPos++;
                if (this._peekChar() === 10) this._bufPos++;
                return line;
        },
        
        nextNumber: function () {
                return +this.nextToken();
        },
        
        nextInt: function ():any {
                return this.nextToken() | 0;
        }
};

function swap<T>(a: T, b: T): [T, T] {
    return [b, a];
}

let t = IO.nextNumber();
while(t--){
	solve();
}


function q(n:number):boolean {
	if (n < 0) return false;
	let r = Math.floor(Math.sqrt(n));
	return r * r === n;
}

function doit(n:number):void{
	n+=10;
}


function solve():void {
	let n = IO.nextNumber();
	if(q(n*(n+1)/2)){
		console.log(-1);
		return ;
	}

	let p:Array<number> = new Array(n);
	let sum = 0;
	for(let i=0; i<n; i++){
		p[i] = i+1;
	}
	for(let i=0; i<n-1; i++){
		if(q(sum+p[i]))[p[i], p[i+1]] = swap(p[i], p[i+1]);
		sum+=p[i];
	}
	console.log(p.join(" "));
}
/*
2 1 3 4
*/