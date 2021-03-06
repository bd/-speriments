#! /usr/bin/python

##sends an email (to self) with attached image

import smtplib
from email.mime.image import MIMEImage

fname = "image.jpg"
f = file(fname)
attachment = MIMEImage(f.read())
from email.mime.multipart import MIMEMultipart

msg = MIMEMultipart('alternative')
msg['Subject'] = 'test of the python mail system'
msg['From'] = fromEmail
msg.attach(attachment)

s = smtplib.SMTP('smtp.gmail.com:587')
s.ehlo()
s.starttls()
s.login("user@gmail.com", "password")
toEmail = 'user'
fromEmail = toEmail
#body did not get sent, though attachment did
body = 'The body of the message'

s.sendmail(fromEmail, toEmail, msg.as_string())