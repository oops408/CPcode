import re

def f1(data):
	p = re.compile('(?P<dept>[A-Z]{2,3}) (?P<num>[0-9]{3})')
	return p.search(data)

obj = f1('CS 101')
dept, num = obj.group('dept'), obj.group('num')

print dept
print num