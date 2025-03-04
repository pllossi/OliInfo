{ NOTE: it is recommended to use this even if you don't understand the following code }

var
    N, i : LongInt;
    D    : Array[0..10-1] of LongInt;

begin
{
    uncomment the two following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    ReadLn(N);

    for i := 0 to 10-1 do D[i] := 0;

    { INSERT YOUR CODE HERE }


    for i:=0 to 10-1 do
        Write(D[i], ' ');
    WriteLn();

end.
