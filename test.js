const yolo = require('./index.js')

const add1 = [ '2MyEcnJgsHMdiHQrpaaknGDnqFohJo9dsMa',
    '2NBSh5iYxD3GjDsHURW5Yo5fyjwwgakPzNW',
    '2MtaE1ujrjsp7UxdCqjagMNA6HeVvM59kQh',
    '2NDvecZK61C7UxBxZZeRDMzQbB8hboG528L',
    '2N5mqcMVrwPxJuFb9gDejuBLEGjE7tYckA7',
    '2Mu2vbVnXPgWeNcRdWFWk1CWt3zXdFX4XdJ',
    '2N1dXA3ZyXZn8dxT2mEbcj4xid77Eu2Csbm',
    '2Mu1DvGh7LxJCvfSExrJxTDCPHRwANZBLwi',
    '2ND7aQkHTVaQpwbqjbXRrKbHa4pVuwga72f',
    '2NEEgvSDu5EZ5LZQ1idKpcZRztEH4UWC5f3',
    '2MxzoFLuQkYfkKXUCE6pz2uwVDfSVCxT8Lv',
    '2MxDKmtoorSt8NZpqiofHjTQYjyfqdH6CwA',
    '2MxnarmdvYQ8FEqCqevirsknXX3mSzEgA8P',
    '2N2WSiBJMCrpZhwYkD6GGukMnhfCNjQysHt',
    '2NDapFhpa1xNRXyz6CqRiWeK3YN3A95sw7E',
    '2MztSxfTzs1dPiY6QbFyNbuzrmEM6K98Dct',
    '2MyqdjWSijzGpcYhQoQnZ4hg7ak3575kzZa',
    '2N1k6tN4iJ1wjjZpzGQMfAHN9uygLPe3MUg',
    '2N91aZizuWXn4Qi5XMgvU1RCMEmSXPEerNR',
    '2N4a8tBbdLeTQkBcxt9pYuMd1DLA7L87Aby',
    '2N73h52ZnkNYYqayYNM2Fb6pQjJtdRoSaui',
    '2MyHRvTRHZsdpvMLwcbbu2Hmr6BAtFmfGSH',
    '2Mx9HkiLx1cdnvfzP8w1TkHbU8jRnDvtMrk',
    '2Mx3pt2g211fALHyZumETZbPQ6cp4CZVqvo',
    '2NC6SbyDDA2JcRRkGQyqpL66zvgjzyyfKmu',
    '2NE2YZ9Lo8MPxnYGLZNTej4BYfaUsoWVRwy',
    '2N52Qr6Z6XnkhwtJ8f7q3CDjc53zY6cDBiM',
    '2NEqy62pUn3PbADTiEKVuepPbnNGWM6vbhB',
    '2MurjE67sxiF751jKj1a5uFa8jp8ukgSUPQ',
    '2NCbZ4vJbKvDdjRXaoPZdXAb8y4FWCtxeGx',
    '2N6a2Zp7oYX1kz8aajnxC11WEMDUnPixvED',
    '2MuP3JJowEUJqPATaVZMwjD8qB2uBrKQRhc',
    '2NFj7zw2AQ52eVMzGRaxEpyJiWQXpA5FzfW',
    '2NA1n8ZDp81nbno75NXEpsRk4ud68Rvkudv',
    '2NCwfCc76Sf6xMYKCurghMHjnT3Mj9uEYyN',
    '2N43tpnpPm4E8YL2mM4dTvVYBmZwKckbi53',
    '2N62idRx46GsbSjCqdpRogGmyCJeYpSKLd3',
    '2NDoTfZtuxEmd8bHaAx2uKhfdEsfwS6f2Tk',
    '2NFAj3yaQTVKK5tXVVCHAww3Bv9BfGgD4gK',
    '2NFQ3vq37VkjGB5DHJahud8VHFWKVHLM1hU' ]

const addresses =  [ '2NFAj3yaQTVKK5tXVVCHAww3Bv9BfGgD4gK',
    '2NFQ3vq37VkjGB5DHJahud8VHFWKVHLM1hU',
    '2MxsCMs8RtpKdutvZWJjdocaaFh78b9Vg1w',
    '2Mtun2WgNZ4cCsdiG8fhMbGF9xqKD95jm2G',
    '2Mz27ZQKFTcw2CsySzx1du8p8w1UNgsX32y',
    '2NCoM7WJCc2hid2TqXEmrrX9zPs92YTmdiP',
    '2MwWNRPdep1qSsVDAt2Gu7y86WeotVsoZaq',
    '2MsJW9sdTARjcV3PyTykyWiDiDbuTu6EVoR',
    '2My1LbQNSNSAAh6N4YG8WHZUPdfvQ4PPNYT',
    '2NC3Kk8WNsJdg3PScGRwuLjibNoFagczLGN',
    '2N6amM9yhLPd4wDyQCZRAt9VPbJqAT5vj9n',
    '2NDo3X1oiRSwWRjEVoK66R8Xp9gUb1pjaPG',
    '2Mu5oRrb3LbgHRizoERKx5Wc9gvYdfyhMLY',
    '2N9btmQc51ufoiA1HwQ4d92KXvFikyyanfM',
    '2N6W7KtVSYXcLrwygc35zTfEVoBJjje9exc',
    '2NCwf6kyKkVouysxJ7e66tPv4ozTCAVEATu',
    '2N8cH794SEt4ig2EBMm91Zgt1g1QxBtkxVG',
    '2MwHjRQ38UTFMsGNqRfo6Zy5PehqsxDQv7R',
    '2NEBvasXAXbjZeUuT7sf12rWCtdEtSvUpb1',
    '2N5FsP7mEb23U3TBVG7Riwqzm3PF2jC8fKT',
    '2N1sm7J1FDMGfAvvJepUJ1g8uv5bsqtLcNd',
    '2N4YwGrbQDAyxjJV6CgLquphPjAfr8JBFSg',
    '2N4gZVRPip8h3LXhMWyBMwByuTevSFpvk7w',
    '2N8ptVXcXktN25dVJo4GxAvqDzWa4YbArPm',
    '2MsgB5hfdiWiFJXKjrdg4pKbhUEQDXUEESv',
    '2NBBJUiLdHct9snv8ho7Q8uyUy8nLDZv8Zw',
    '2NBD5LPHbhYiVUZwao9Rce2R2GaieczJV88',
    '2NCTTCgNeH9pSmZxnPVmfZ9CSo6rdvAG7yp',
    '2Mzvic26fT4LCPttT8qnkouEmqG2gVBxk6M',
    '2My75hBAhxaZ6TDJWqaU857S8uNVH2CY7Lh',
    '2Mw6DmwWZMh284bZb7YDoHgFqcPHZ8jdV9y',
    '2MtK5iottB5fGTM5U4osjzwLjR3Cz5b7rpi',
    '2N6JwDhnTkiyRh8srhfnhp74UQ8yKTwQnFt',
    '2NBdjQnjrkt5VbSDt8zYRo4FCzFPZmA1Dz3',
    '2NFseMe5vEnywfcjvEKfbG3PYus4hyP5KnZ',
    '2MsMgVEyQtnefMCUC2mQmKMpR1T2HgExqKx',
    '2N2r362ZXvRn4AMQFeXxuVRP1NMfDkK5Bk9',
    '2Mvpb3VC3HrrBc8mS2fh4nnV2woRhPe4K7U',
    '2MwbHrj6xiZJW3V6uwNzPsj8uyA6gt5EzLB',
    '2N8UYMnDTkCga2qkN1yR14cZJ9kE43mX5kV' ]

const testnetMode = true
yolo.getTransactions(add1, testnetMode).then(txs => {
  console.log(`first one finished`)
  console.log(txs);
  return yolo.getTransactions(addresses, testnetMode)
}).then(t => {
  console.log(`finished`)
  console.log(t);
}).catch(err => {
  console.log(err);
  console.log(`onetuhnatuhoetnh`)
})


// yolo.getTransactions(add1).then(txs => {
//   console.log(`first one finished`)
//   console.log(txs);
// }).catch(err => {
//   console.log(err);
//   console.log(`onetuhnatuhoetnh`)
// })
