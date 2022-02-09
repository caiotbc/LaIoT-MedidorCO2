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
client.on('connect', () => {
  console.log('Connected')
  client.subscribe([topic], () => {
    console.log(`Subscribe to topic '${topic}'`)
  })

})

let devices = 
{
    medidor1ID : "661e70e5",
    medidor1Token : "4Pvx54FMyH2A4PSgcwv3",
    medidor2ID : "a82f70be",
    medidor2Token : "3SGJjIFXUsDAzSTEW7XU"
}

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
    co2 = parseInt(decoded.substring(0, 4) , 16);
    temperatura = parseInt(decoded.substring(4, 8),16);
    umidade = parseInt(decoded.substring(8, 12),16);
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
            mgas: co2
        })
        path = devices.medidor1Token;
    }
    else if(obj.meta.device_addr==devices.medidor2ID)
    {
        data = JSON.stringify({
            mgas: co2
        })
        path = devices.medidor2Token;
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
