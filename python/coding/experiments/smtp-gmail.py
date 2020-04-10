#!/usr/bin/env python3

import smtplib

sent_from = 'moi'
to = ['to@a.com']
subject = 'First test'
body = 'mardi 25 fevrier 2020, 01:20:39 (UTC+0100)'
email_text = "Dernier message envoye en python via smtplib... Option de securite reactive pour le compte doali.phone"

try:
        smtpserver = smtplib.SMTP('smtp.gmail.com', 587)
        smtpserver.ehlo()
        smtpserver.starttls()
        smtpserver.login('a@g.com', 'passwd!')
        smtpserver.sendmail(sent_from, to, email_text)
        smtpserver.close()
        print('Email sent')
except:
        print("Error while attempting to send email")
        print("Check your policy security on your google account")

