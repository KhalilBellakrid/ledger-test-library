var axios = require('axios'),
    util = require("util");

const address = "1HE4ShfmuG7AdVr5RpaCtXfsJYYQQFCj1T";
const addresses =  [ "2N68EF7dYiUGVUHAGoWtYFXo7NfRvNraGjn",
    "2N6tZe936iWaWVKwQ6TN2uHE9uVSh1SfsBR",
    "2MsSBqgqWFF5ovaYTWHa3vZwFsGzKR6wbgX",
    "2N1YzttARiNVhdkGp2h1XBEsqQDwLHWjrH8",
    "2N5HTfb8UyqdFo2v6A83JeT9hiHaEfRXUxv",
    "2N8fcrnV1HttHcexih26QYLU5rfTS3Yddis",
    "2N96SZhn4mZvEcYGEMjpaB5haYDDXrZvBky",
    "2Mt5rnziEwX6h3cjQajTu6dNKMTXYTGRERp",
    "2NARDqFg9Lv9afpahJurRpdeXJCHnDsMEXW",
    "2N5a6DbXyaYeTgcDyf6wQGERs8qGfijjobJ",
    "2N4mSidD6yCcZg1vN1i4mGptaqQuQPq2vDH",
    "2N4U2ntSXan3avkjdj7KBFFDqpMdjrTpUs4",
    "2NGCeqXe7LX1Fi98x1N6tw1hYa9dqKQ8LNu",
    "2N5qEKjpp2NUdNcJbj2RjudJrXuhZAgthKq",
    "2N2ZqmwEHi3Uxfmfxd2oMX5629tQknFNmED",
    "2NEnEZyagr2iuH5kAo3jsYXTE5nuaabfyHL",
    "2My7pVouM7Rv1AikAUdjv4YUpNmrKiYFyAu",
    "2N5CmN6XQhuyuVFYAq21CnWQr1bzq2e2Qqg",
    "2MuKKG1eZpYDp5WuwpYhzQr1ZQJkk2pBLRg",
    "2MskuYT7D8yULrodeMRvXSmqwEPWKgxbWgo",
    "2Mz2vH5Hp8L4EA6W5VsRfG1ajkhe8qkkzPn",
    "2MzBnYegzRo1bTh4rYuvTNnebpYvkRw4nX6",
    "2N4PEsT8syT8vaLvrfrTaKQ3iLkvYZ8DrS4",
    "2NDgWcSxboLJk1tJXZoLfQBqffH9sZkUbrq",
    "2MtuTrHAr7vNXniad16YVn4kCGS7MNXyMHY",
    "2MwKrcD6ZpVmL9YzW8GSgNyd3mGhdf1a1M4",
    "2NC3jKCnGjURjTzAJkmzj3kg4HL4XzWgudw",
    "2Mu2VadYUBBMynfANkkWQh1SzxRtcK6ajou",
    "2N4bPYUz5ReNgxYbmgwTRsMxpwBoPAt3P84",
    "2NFTWNgwopQS6e91nFtxnSHwqSmD68FLKra",
    "2Mxf7PM8Dw6xkJ8U8c2vpQ2JEk7t3WDchxG",
    "2N1xrWqUz7R6ANwrVm34Q4Dxy35UYf3AgXp",
    "2MvXj1thb8Db4E93VVXjdowXe2C4r5SJRmW",
    "2NFwC3vjbrEbdktWCM8793oK9uesC7uV7w7",
    "2MsP8JdBAMB1kNT1Ly4Be2sbTqjNwviLpEZ",
    "2NDbrZmGAqGbzXJQUDadasynDLmvS1Hba42",
    "2N7H4Ly1qQFW5Jkn6HEs3vNb2ZPkhQqaUm6",
    "2MsSJbQDABqanQTHmBsnPjUtk1WeWGqc55U",
    "2MvqmvVQ3T6ozMfrWoQ3sgyX462XjiGbpnF",
    "2N5tCeeFs4H5rLfh6jMKu5p6smFqyHNcfew",
    "2MuYUZSAVCFo56fDB7afDw8VP4HwCi7wbqt",
    "2MsPRGEpNuz4s5ZADgctjc93u3rdBypikJD",
    "2MsdxgxVSR3rPjhZGDBK8tXb3smHBQBmcpJ",
    "2NBwMvwGhzFM161QtthPxiGaQTJWzFa8ex7",
    "2MvPP7TxN9wbxt9HaBJC3szQd34i68aZwou",
    "2NE2uRfnvDdnGmLWhrSYSmRccsmwbHtGojZ",
    "2Mwxp1Y4g19UfQoCpLe4jTQ5Wu9y758yWwz",
    "2NGXLqwcxHWXu6DvwuSsU9yunZy2tRZLEjV",
    "2NFAWDbPUSSKdAkonvJ1uysEq8FLHCtnWwv",
    "2MvdyBAYNhobLqy2mQbR2gEoryAFpdu7NJ4",
    "2MtoQpdMhoFnnnjTgRhK5nV2aTvrTgfi3Rx",
    "2Mz7jCwchkR8RFSjWa2ANU9CSZ11obAjWKC",
    "2MtKC4Z8g4fJuYg9XNagqxGTn4zayxPY7Bt",
    "2NAW889LLJJCjVqeh1yit1RekE6QhjFo6X5",
    "2N4xkKnfD7FeVGxH9yxWCkVvsubxZExBFzy",
    "2N3RPuPUhGWPzwaSkbnSg5o5rLu1Voitf2C",
    "2N7MZZ3UanQ3nQAwSn11F54kCZB1itcuC26",
    "2N7ZFociU8UYSAwn3ePqHr6tNzXRavaWneQ",
    "2N3iuEbAysfYwhFbJCoHuYP63APmr6QSKKG",
    "2NBH6ZgRMDjtbhrNZt9uTZKsTCNKxXFcWPT",
    "2NBUbEU28jEdKfDfR8yLyx76mi817n367Xs",
    "2MujmNPFwZmzgnN5E4hUpd8aZy34KmVJGrM",
    "2MvKun7VHK5sgoLwvTchNDV3ttPwjcjepZ3",
    "2MsHFBJcCQveukhuNykrrzZdYWAwRNcwfhP",
    "2NBpGFF2XUXNQjMXQJ7JUVWjCeimC9otKcG",
    "2MuhACRNYZWu2MRSZ4iiEeYNtvgTCT8Hu3G",
    "2N1zDGoB86Gi6VjknS7FS9cD4dEkE4qpEZk",
    "2MvvMbE6tx9NNv6TyK1a6Z7N8QzFZyKMmeU",
    "2N9wjafmzVhFAp5iVBnwNyhK15e4oHw9TJB",
    "2NBunDFwGZCRckGqpqTYsAhSpEtdWhbdSMY",
    "2N7Jou8jaRQEywEPRBaLsFURBzcij1qUvhi",
    "2N2vqx1xK2dspNK5ivmFxJrcHgJrPGJFH1L",
    "2N6yduEYT1yFGoEvKFSSQCii116wGA5KBAo",
    "2NDJa9M8FyR2V8ERReunhC6dogArYquaSyk",
    "2MxWUH73djkdVfB7evBZeBX5nWSBYtDndX9",
    "2N63UddJ181bPzqBWKpVHyc28MAN56u9TWA",
    "2N3WntYSmk1E3jj8fJfEobVbp3sKAm5d5cF",
    "2NBRV23x4L8aogCpb11k9r2gm2xQJLg2USA"];

//lazy loading
var binding = null;
function loadBinding(){
    if(!binding){
        binding = require('bindings')('ledgerapp_nodejs');
    }
}

/*
    Http request to initialize NJSHttpModule
    callback: NJSCallbackModule to recursively request token + txs
 */
const axiosRequest = (url,headers,callback) => {

    const header = {
        method: 'get',
        url: url
    }

    //Headers may be a string 'No headers'
    if(typeof headers === 'object'){
        var tokenHeader ={}
        tokenHeader[headers['0']] = headers['1'];
        header['headers'] = tokenHeader;
    }

    axios(header).then(function(response) {
        //console.log(JSON.stringify(response.data))
        callback.onSuccess(JSON.stringify(response.data));
        }).catch(reject => {
            console.log("Reject: ",reject.message)
    });
}
/*
    NJSHttpModule
    Test Module with a simple http call to Ledger Api
 */
function NJSHttpModule(req) {

    loadBinding();
    //inherit from binding.ledgerapp_nodejs
    //try binding.ledgerapp_nodejsapply(this,argument)
    var thisPlusArgs = new Array(arguments.length + 1);
    thisPlusArgs[0] = null;
    for(var i = 0; i < arguments.length; i++)
        thisPlusArgs[i + 1] = arguments[i];
    this._raw = new (Function.prototype.bind.apply(binding.NJSHttpModule,
        thisPlusArgs))(req);
    //inherit from this._raw
    for(var j in binding.NJSHttpModule.prototype){
        this[j] = binding.NJSHttpModule.prototype[j].bind(this._raw);
    }
}


/*
    NJSCallbackModule
 */
function NJSCallbackModule() {

    loadBinding();

    //inherit from binding.ledgerapp_nodejs
    //try binding.ledgerapp_nodejsapply(this,argument)
    var thisPlusArgs = new Array(arguments.length + 1);
    thisPlusArgs[0] = null;
    for(var i = 0; i < arguments.length; i++)
        thisPlusArgs[i + 1] = arguments[i];
    this._raw = new (Function.prototype.bind.apply(binding.NJSCallbackModule,
        thisPlusArgs))();
    //inherit from this._raw
    for(var j in binding.NJSCallbackModule.prototype){
        this[j] = binding.NJSCallbackModule.prototype[j].bind(this._raw);
    }
}

/*
    NJSThreadDispatcher
    Test Module to provide contexts and dispatch tasks into them
 */
function NJSThreadDispatcher() {
    loadBinding();
    var thisPlusArgs = new Array(arguments.length + 1);
    thisPlusArgs[0] = null;
    for(var i = 0; i < arguments.length; i++)
        thisPlusArgs[i + 1] = arguments[i];
    this._raw = new (Function.prototype.bind.apply(binding.NJSThreadDispatcher,
        thisPlusArgs))();
    //inherit from this._raw
    for(var i in binding.NJSThreadDispatcher.prototype)
        this[i] = binding.NJSThreadDispatcher.prototype[i].bind(this._raw);
}

/*
    Main Api
 */
function NJSApi() {
    loadBinding();
    var thisPlusArgs = new Array(arguments.length + 1);
    thisPlusArgs[0] = null;
    for(var i = 0; i < arguments.length; i++)
        thisPlusArgs[i + 1] = arguments[i];
    this._raw = new (Function.prototype.bind.apply(binding.NJSApi,
        thisPlusArgs))();
    //inherit from this._raw
    for(var i in binding.NJSApi.prototype)
        this[i] = binding.NJSApi.prototype[i].bind(this._raw);
}
/*
    Observer to listen on Api updates
 */
function NJSTransactionListVmObserver() {
    loadBinding();
    var thisPlusArgs = new Array(arguments.length + 1);
    thisPlusArgs[0] = null;
    for(var i = 0; i < arguments.length; i++)
        thisPlusArgs[i + 1] = arguments[i];
    this._raw = new (Function.prototype.bind.apply(binding.NJSTransactionListVmObserver,
        thisPlusArgs))();
    //inherit from this._raw
    for(var i in binding.NJSTransactionListVmObserver.prototype)
        this[i] = binding.NJSTransactionListVmObserver.prototype[i].bind(this._raw);
}

/*
    Test
 */

function getTransactions(addresses) {
  return new Promise(resolve => {
    const LGHttp = new NJSHttpModule(axiosRequest);
    const LGThreadDispatcher = new NJSThreadDispatcher();
    const LGApi = new NJSApi(LGHttp._raw, LGThreadDispatcher._raw);
    const LGObserver = new NJSTransactionListVmObserver(LGApi._raw);

    LGObserver._raw.start(addresses, txs => {
      resolve(txs.map(JSON.parse));
      LGObserver._raw.stop();
    });
  });
}

exports.getTransactions = getTransactions;
exports.axiosRequest = axiosRequest;
exports.NJSHttpModule = NJSHttpModule;
exports.NJSApi = NJSApi;
exports.NJSThreadDispatcher = NJSThreadDispatcher;
exports.NJSTransactionListVmObserver = NJSTransactionListVmObserver;
