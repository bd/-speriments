#!/usr/bin/python
import os, re
import sys
import smtplib

from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

mails = open('emails.txt','r+')
#mailList = mails.read()
mailList = [i.strip() for i in mails.readlines()] 
directory = "pics"

SMTP_SERVER = 'smtp.gmail.com'
SMTP_PORT = 587

sender = 'sender@gmail.com'
password = "password"
recipient = mailList 
subject = 'Python (-++-) Test'
message = 'Images attached.'

def main():
    msg = MIMEMultipart()
    msg['Subject'] = 'Python (-++-) Test'
    msg['To'] = recipient
    msg['From'] = sender

    files = os.listdir(directory)
    pngsearch = re.compile(".png", re.IGNORECASE)
    files = filter(pngsearch.search, files)
    for filename in files:
        path = os.path.join(directory, filename)
        if not os.path.isfile(path):
            continue

        img = MIMEImage(open(path, 'rb').read(), _subtype="png")
        img.add_header('Content-Disposition', 'attachment', filename=filename)
        msg.attach(img)

    part = MIMEText('text', "plain")
    part.set_payload(message)
    msg.attach(part)

    session = smtplib.SMTP(SMTP_SERVER, SMTP_PORT)

    session.ehlo()
    session.starttls()
    session.ehlo
    session.login(sender, password)

    session.sendmail(sender, recipient, msg.as_string())
    session.quit()

if __name__ == '__main__':
    main()