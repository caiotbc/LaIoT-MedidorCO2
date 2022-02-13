const mqtt = require('mqtt')
const http = require('http')

const host = 'localhost'
const port = '1883'
const clientId = `mqtt_${Math.random().toString(16).slice(3)}`

const connectUrl = `mqtt://${host}:${port}`
const client = mqtt.connect(connectUrl, {
  clientId,
  clean: true,
  connectTimeout: 4000,
  username: 'emqx',
  password: 'public',
  reconnectPeriod: 1000,
})

const topic = 'test/message'
const aionedge = 'aiontheedge'
client.on('connect', () => {
  console.log('Connected')
  client.subscribe([topic], () => {
    console.log(`Subscribe to topic '${topic}'`)
  })

})

// client.on('connect', () => {
//   console.log('Connected')
//   client.subscribe([aionedge], () => {
//     console.log(`Subscribe to topic '${aionedge}'`)
//   })
// 
// })


let devices = 
{
    medidor1ID : "661e70e5",
    medidor1Token : "4Pvx54FMyH2A4PSgcwv3",
    medidor2ID : "54f74976",
    medidor2Token : "3SGJjIFXUsDAzSTEW7XU",
    medidor3ID : "530d4623",
    medidor3Token : "zTQIiaOkob1w5wrl2LTF",
    medidor4ID : "37033f9b",
    medidor4Token : "DcsmZm8m229qBwklca6o"
}

client.on('message', (aionedge, payload) => {
    console.log("AI ON EDGE CONECTADO");
    console.log(payload)
    
})

client.on('message', (topic, payload) => {
  //console.log('Received Message:', topic, payload.toString())
  const obj = JSON.parse( payload.toString());
  console.log(obj.meta.device_addr);
  
  let decoded = 0, co2 = 0, temperatura = 0, umidade = 0;
  if(obj.params.payload)
  {
    let buff = Buffer.from(obj.params.payload, 'base64'); 
    decoded = buff.toString('hex');
    //console.log(decoded);
    analog = parseInt(decoded.substring(0, 4) , 16);
    co2 = (analog/4096)*3.3;
    temperatura = parseInt(decoded.substring(4, 8),16)/100;
    umidade = parseInt(decoded.substring(8, 12),16)/100;
    console.log("CO2 = " , co2);
    console.log("Temp = " , temperatura);
    console.log("Humi = " , umidade);
  }
    let data = JSON.stringify({
    track: 12
})
    let path = "";
    
    
    if(obj.meta.device_addr==devices.medidor1ID)
    {
        data = JSON.stringify({
            mgasanalog: analog,
            mgas: co2,
            mtmp: temperatura,
            mhum: umidade
        })
        path = devices.medidor1Token;
    }
    else if(obj.meta.device_addr==devices.medidor2ID)
    {
        data = JSON.stringify({
            mgasanalog: analog,
            mgas: co2,
            mtmp: temperatura,
            mhum: umidade
        })
        path = devices.medidor2Token;
    }
    else if(obj.meta.device_addr==devices.medidor3ID)
    {
        data = JSON.stringify({
            mgasanalog: analog,
            mgas: co2,
            mtmp: temperatura,
            mhum: umidade
        })
        path = devices.medidor3Token;
    }
    else if(obj.meta.device_addr==devices.medidor4ID)
    {
        data = JSON.stringify({
            mgasanalog: analog,
            mgas: co2,
            mtmp: temperatura,
            mhum: umidade
        })
        path = devices.medidor4Token;
    }
    
    
        const options = {
        hostname: 'monitordeenergia.ml',
        port: 8080,
        path: '/api/v1/'+path+'/telemetry',
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Content-Length': data.length
        }
        }

        const req = http.request(options, res => {
        console.log(`statusCode: ${res.statusCode}`)

        res.on('data', d => {
            process.stdout.write(d)
        })
        })

        req.on('error', error => {
        console.error(error)
        })


        req.write(data)
        req.end()

})
