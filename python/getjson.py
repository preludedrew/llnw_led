import urllib2
import json
import os

DELIVERY_URL = 'http://minion.vm.phx2.llnw.net:8080/json/uptime_delivery.json'

# Get File
json_data = urllib2.urlopen(DELIVERY_URL)
data = json.load(json_data)

# Print Output
#print('Days since last outage:')
#print(data['days_since'])
#print('Max days without outage:')
#print(data['max_days'])

# Kill the previous process
os.system("killall llnw-led")

# Open the new process with the given arguments
cmd = "/opt/llnw_led/llnw-led -s {0} -m {1}".format(data["days_since"], data["max_days"])

os.system(cmd)
# Close File
json_data.close()
