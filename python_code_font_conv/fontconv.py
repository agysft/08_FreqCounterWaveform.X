import csv
import StringIO

ftest = open('font16.csv','rb')
reader = csv.reader(ftest)

xdata = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
sdata = [ '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','' ]
rowdata = ''
for row in reader:
#	for i in range(16):
#		print format( int(row[i], 16), '016b')

	rowdata = '{\n'
#	for i in range(16):
	for i in reversed(range(16)):
#		for j in range(16):
		for j in reversed(range(16)):
			xdata[i] = xdata[i] << 1
			xdata[i] = xdata[i] | ((int(row[j], 16) >> i) & 1)
		if i<12 :
			xdata[i] = xdata[i] & 0xffff
			sdata[i] = '0b' + format( xdata[i], '016b') + ',\n'
			rowdata = rowdata + sdata[i]
#		sdata[i] = '0x' + format( xdata[i], '04x')
#		rowdata = rowdata + sdata[i] + ','
#		print ( sdata[i] )
#		print format( xdata[i], '04x')
#		print format( xdata[i], '016b')
#		print format( hex(xdata[i]))
	rowdata = rowdata.rstrip(',\n') + '\n},\n'
	print rowdata

ftest.close()

