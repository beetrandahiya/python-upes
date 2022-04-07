import os 


print("content-type: text/html\r\n\r\n")

print("<font size=+1>Environment</font>")

for param in os.environ.keys():
    print("<br> %20s = %s" % (param, os.environ[param]))

import cgi, cgitb

form=cgi.FieldStorage()

firstname=form.getvalue('firstname')
lastname=form.getvalue('lastname')

print("content-type: text/html\r\n\r\n")
print("<html>")
print("<head>")
print("<title>Hello - Second CGI Program</title>")
print("</head>")
print("<body>")
print("<h1>Hello %s %s</h1>" % (firstname, lastname))
print("</body>")
print("</html>")
