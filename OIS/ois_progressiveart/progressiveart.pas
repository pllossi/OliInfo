{ NOTE: it is recommended to use this even if you don't understand the following code }

const
    MAXN = 1000;

var
    K, L, M, N, i : LongInt;
    A             : Array[0..MAXN-1] of AnsiString;

begin
{
    uncomment the two following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    ReadLn(N, M, L, K);

    for i := 0 to MAXN-1 do A[i] := '';

    { INSERT YOUR CODE HERE }

    WriteLn('YES');
    for i:=0 to N-1 do
        WriteLn(A[i]);

end.
