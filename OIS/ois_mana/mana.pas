{ NOTE: it is recommended to use this even if you don't understand the following code }

const
    MAXN = 100000;

var
    K, N, i : LongInt;
    C       : Array[0..MAXN-1] of LongInt;
    M       : Int64;

begin
{
    uncomment the two following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    ReadLn(N, K);

    for i:=0 to N-1 do
        Read(C[i]);
    ReadLn();

    M := 0;

    { INSERT YOUR CODE HERE }


    WriteLn(M);

end.
