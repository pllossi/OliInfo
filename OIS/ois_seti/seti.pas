function receive(N: longint; var V: array of longint): longint;
begin
    (* insert your code here *)
    receive := 42;
end;


const
    MAXN = 1000000;
var
    N, i  : longint;
    V     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, V[i]);

    writeln(fw, receive(N, V));
    close(fr);
    close(fw);
end.
