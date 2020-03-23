const express = require("express");

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')

//serialport for Zumo
const port = new SerialPort('COM13', {baudRate: 9600})
const Discord = require('discord.js');
const client = new Discord.Client();
const config = require('./config.json');
const fs = require('fs');

port.on('open', function () {
  console.log('Communication is on!')
})
client.on('ready', () => {
  console.log(`Logged in as ${client.user.tag}!`);
});

client.on('message', msg => 
{

if(msg.author.id == 635883330797043723) {return}

    else{
        console.log(msg.author.id);
        console.log(config.client_id);
            
            if(msg.content === "/inst"){
                msg.reply("do /forward, /back, /left or /right")
            }

            else if(msg.content === "/forward"){
                const parser = new Readline()
                port.pipe(parser)

                parser.on('data', line => console.log(`> ${line}`))
                port.write('1')
                msg.reply("Going Forward");
            }

            else if(msg.content === "/back"){
                const parser = new Readline()
                port.pipe(parser)

                parser.on('data', line => console.log(`> ${line}`))
                port.write('2')
                msg.reply("Going Back");
            }

            else if(msg.content === "/left"){
                const parser = new Readline()
                port.pipe(parser)
                parser.on('data', line => console.log(`> ${line}`))
                port.write('3')
                msg.reply("Going Left");
            }

            else if(msg.content === "/right"){
                const parser = new Readline()
                port.pipe(parser)
                parser.on('data', line => console.log(`> ${line}`))
                port.write('4')
                msg.reply("Going Right");
            }

            else if(msg.content === "/180"){
                const parser = new Readline()
                port.pipe(parser)
                parser.on('data', line => console.log(`> ${line}`))
                port.write('5')
                msg.reply("Doing a 180");
            }
            else{ return msg.reply("Invalid Instruction, type /inst for instructions")};
     }
});

client.login(config.token);

// SerialPort.list().then(
//   ports => ports.forEach(console.log),
//   err => console.error(err)
// )