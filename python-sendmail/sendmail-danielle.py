import smtplib
TO = 'someGreatPerson@gmail.com'
SUBJECT = 'Test Email'
TEXT = 'Test Email From Py Script'

gmail_sender = 'sender@gmail.com'
gmail_passwd = 'sender\'sPassword'
server = smtplib.SMTP( 'smtp.gmail.com', 587)
server.ehlo()
server.starttls()
server.ehlo()
server.login('gmail_sender', 'gmail_passwd')

BODY = '\r\n'.join([
        'To: %s' % 'TO',
        'From: %s' % 'gmail_sender',
        'Subject: %s' % 'SUBJECT',
        '',
        'TEXT'
        ])

try:
    server.sendmail (gmail_sender, [TO], BODY)
    print ("email sent")
except e:
    print ("poop" + e)
server.quit()