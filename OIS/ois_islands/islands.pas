{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 1000;

{ input data }
var
    R, C, i, j  : longint;
    M           : array[0..MAXN-1, 0..MAXN-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(R, C);
    for i:=0 to R-1 do
    begin
        for j:=0 to C-1 do
            read(M[i,j]);
        readln();
    end;

    { insert your code here }

    writeln(42); { print result }
end.
