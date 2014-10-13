#!/usr/bin/python

import json

JSON_FILE = "/tmp/jsonfile"
MOD_FILE = "/tmp/testfile"
DEBUG = True

def updateJson(curr, max):

    with open(JSON_FILE, "r") as jsonFile:
        currInfo = json.load(jsonFile)

    # Current days since
    if curr > -1:
        currInfo["curr"] = curr
    else:
        currInfo["curr"] = currInfo["curr"] + 1

    # Max days since
    if (max > -1):
        currInfo["max"] = max
    else:
        if (currInfo["curr"] >= currInfo["max"]):
            currInfo["max"] = currInfo["curr"]
        
    if (DEBUG):
        print "Printing to file: [ ", currInfo, "]"
    
    with open(JSON_FILE, "w") as jsonFile:
        jsonFile.write(json.dumps(currInfo))

#Open our file created by the IM site 
with open(MOD_FILE, "r+") as modFile:
    if not modFile.read(1):
        print "File is blank"
        nodata = True
    else:
        print "File is not blank"
        nodata = False
    modFile.seek(0)
    data = modFile.read().strip('\n').split(',')

# Only way I've been able to clear the file
f = open(MOD_FILE, "w")

# Need to kill this file once we're done with it.

if (nodata):
    new_data_curr = -1
    new_data_max = -1
else:
    new_data_curr = int(data[0])
    new_data_max = int(data[1])

updateJson(new_data_curr, new_data_max)
