{ NOTE: it is recommended to use this even if you don't understand the following code }

var
    N, A     : longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);

    { SAMPLE INTERACTION, REPLACE WITH YOUR CODE }
    writeln(1, 2);
    flush(output);
    readln(A);

    write('! ')
    for i:=0 to N-1 do
        write(i + 1);
    flush(output);
    
end.
