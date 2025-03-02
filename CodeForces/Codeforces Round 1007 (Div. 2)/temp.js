/* -------------------------------------------------------- */
/*   ( The Authentic JS CodeBuff )
 ___ _                      _              _ 
 | _ ) |_  __ _ _ _ __ _ __| |_ __ ____ _ (_)
 | _ \ ' \/ _` | '_/ _` / _` \ V  V / _` || |
 |___/_||_\__,_|_| \__,_\__,_|\_/\_/\__,_|/ |
                                        |__/ 
 */
/* ---------------------------------------------------------   */
/*    Youtube: https://youtube.com/@code-with-Bharadwaj        */
/*    Github : https://github.com/Manu577228                  */
/* ----------------------------------------------------------- */

// Template Starts here Fast IO!

let V8Flags = [
    '--max-old-space-size=4096', 
    '--max-semi-space-size=16', 
    '--stack-size=65536', 
    '--reclaim-unused-memory',
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

let inputBuffer = Buffer.allocUnsafe(1e7);
let inputIndex = 0,
        inputLength = 0;
let outputBuffer = Buffer.allocUnsafe(1e7);
let outputIndex = 0;

let fs = require('fs');
inputLength = fs.readSync(process.stdin.fd, inputBuffer, 0, inputBuffer.length, null);

function readInt() {
        let num = 0,
                sign = 1;
        while (inputIndex < inputLength && (inputBuffer[inputIndex] < 48 || inputBuffer[inputIndex] > 57)) {
                if (inputBuffer[inputIndex] === 45) sign = -1;
                inputIndex++;
        }
        while (inputIndex < inputLength && inputBuffer[inputIndex] >= 48 && inputBuffer[inputIndex] <= 57) {
                num = num * 10 + (inputBuffer[inputIndex++] - 48);
        }
        return num * sign;
}

function readBigInt() {
        let num = 0n,
                sign = 1n;
        while (inputIndex < inputLength && (inputBuffer[inputIndex] < 48 || inputBuffer[inputIndex] > 57)) {
                if (inputBuffer[inputIndex] === 45) sign = -1n;
                inputIndex++;
        }
        while (inputIndex < inputLength && inputBuffer[inputIndex] >= 48 && inputBuffer[inputIndex] <= 57) {
                num = num * 10n + BigInt(inputBuffer[inputIndex++] - 48);
        }
        return num * sign;
}

let isFirstInLine = true;

function writeInt(value, isLast = false) {
        if (!isFirstInLine) {
                outputBuffer[outputIndex++] = 32;
        }
        if (value < 0) {
                outputBuffer[outputIndex++] = 45;
                value = -value;
        }
        let digits = [];
        do {
                digits.push(value % 10);
                value = Math.floor(value / 10);
        } while (value > 0);
        for (let i = digits.length - 1; i >= 0; i--) {
                outputBuffer[outputIndex++] = 48 + digits[i];
        }
        isFirstInLine = isLast;
        if (isLast) {
                outputBuffer[outputIndex++] = 10;
                isFirstInLine = true;
        }
}

// Template Ends here!

function d(c, p, e, g) {
        let s = [];
        s.push([c, p]);
        
        while (s.length > 0) {
                let [u, v] = s.pop();
                
                for (let n of g[u]) {
                        if (n !== v) {
                                e[n] = e[u] + 1;
                                s.push([n, u]);
                        }
                }
        }
}

let t = readInt();
while (t--) {
        let n = readInt();
        let s = readInt();
        let e = readInt();
        
        let a = new Array(n + 1);
        for (let i = 0; i <= n; i++) {
                a[i] = [];
        }
        
        for (let i = 1; i < n; i++) {
                let x = readInt();
                let y = readInt();
                a[x].push(y);
                a[y].push(x);
        }
        
        let h = new Int32Array(n + 1).fill(-1);
        h[e] = 0;
        
        // Iterative DFS instead of recursive to avoid stack overflow
        d(e, 0, h, a);
        
        let r = new Uint32Array(n);
        for (let i = 0; i < n; i++) {
                r[i] = i + 1;
        }
        
        // Use a more efficient sorting approach
        let m = new Array(n);
        for (let i = 0; i < n; i++) {
                m[i] = [r[i], h[r[i]]];
        }
        
        m.sort((j, k) => k[1] - j[1]);
        
        for (let i = 0; i < n; i++) {
                writeInt(m[i][0], i === n - 1);
        }
}

fs.writeSync(process.stdout.fd, outputBuffer.slice(0, outputIndex));
