{ NOTE: it is recommended to use this even if you don't understand the following code }

const
    MAXT = 10000;

var
    L, T, i, j : LongInt;
    S, D       : Array[0..2] of AnsiString;

begin
{
    uncomment the two following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    ReadLn(T);

    for i:=0 to T-1 do
    begin
        for j:=0 to 2 do
            Read(S[j]);
        for j:=0 to 2 do
            Read(D[j]);

        L := 0;

        { INSERT YOUR CODE HERE }


        WriteLn(L);
    end;

end.
