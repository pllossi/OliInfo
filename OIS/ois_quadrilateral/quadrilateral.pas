{ NOTE: it is recommended to use this even if you don't understand the following code }

const
    MAXN = 100000;

var
    N, i : LongInt;
    S    : Array[0..MAXN-1] of Int64;
    Q    : Array[0..4-1] of LongInt;

begin
{
    uncomment the two following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    ReadLn(N);
    
    for i:=0 to N-1 do
        Read(S[i]);
    ReadLn();
    
    for i := 0 to 4-1 do Q[i] := 0;
    
    
    { INSERT YOUR CODE HERE }
    
    
    for i:=0 to 4-1 do
        Write(Q[i], ' ');
    WriteLn();

end.
