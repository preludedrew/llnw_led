import urllib.request
import json

# Get File
urllib.request.urlretrieve('http://scratchonthebreak.com/numbers.html', 'numbers')

# Open and Load File
json_data=open('numbers')
data = json.load(json_data)

# Print Output
print('Days since last outage:')
print(data['days_since'])
print('Max days without outage:')
print(data['max_days'])

# Close File
json_data.close()
