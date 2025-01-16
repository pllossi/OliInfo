function erase(N: longint; var S: array of longint): longint;
begin
    (* insert your code here *)
    erase := 42;
end;


const
    MAXN = 5000;
var
    N, i  : longint;
    S     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, S[i]);

    writeln(fw, erase(N, S));
    close(fr);
    close(fw);
end.
