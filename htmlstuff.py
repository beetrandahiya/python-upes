import os 


print("content-type: text/html\r\n\r\n")

print("<font size=+1>Environment</font>")

for param in os.environ.keys():
    print("<br> %20s = %s" % (param, os.environ[param]))