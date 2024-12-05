{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 100000;

{ input data }
var
    N, K, i  : longint;
    V        : array[1..MAXN] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, K);
    for i:=1 to N do
        read(V[i]);
    readln();

    { insert your code here }

    writeln(42); { print result }
end.
