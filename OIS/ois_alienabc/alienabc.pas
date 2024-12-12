{ WARNING: this is a generic template, not specific to any task }

{ constraints }
const
    MAXL = 100;

{ input data }
var
    T : integer;
    S : string;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    { read number T in a single line }
    readln(T);
    { read all numbers V[i] in the next line }
    for i:=0 to T-1 do
    begin
       readln(S);
       
       { insert your code here }

       { write result in a single line }
       writeln(-1);
    end
end.
