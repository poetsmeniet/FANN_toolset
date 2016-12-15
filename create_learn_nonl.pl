#!/usr/bin/perl
if(!$ARGV[0] or !$ARGV[1] or !$ARGV[3]){
	print "Usage: create_learn.pl <source file> <learn file> <output value: 0/1) <nr of inputs>. Ouputs bytes of file as int and append to data learn file\n";
	exit 1;
}
my $outputValue;
if(!$ARGV[2]){
	$outputValue=0;	
}else{

	$outputValue=$ARGV[2];	
}

my $bytesread=0;
my $bitsread=0;
my $maxBytes=$ARGV[3];

my $learnbuf=`./load.o $ARGV[0]`;

#print $learnbuf;
#write the values to learning file, including output value
open FH, ">>$ARGV[1]" or die "Couldn't open output file: $!"; 
print FH $learnbuf."\n";
if($outputValue==0){
	$outputValue="1 0";
}elsif($outputValue==1){
	$outputValue="0 1";
}else{
	$outputValue="0 1";
}
print FH $outputValue."\n";
close(FH);
print "outputValue: $outputValue\n";

#update 1st line of learn file to correspond with new contents
# - get values of first line (ex: 2 200 1) 0: nr of learning entries: increment one. 1: nr of inputs, static. 2: number of outputs: static: 1
my $lineOne=`head -1 $ARGV[1]`;
print "lineOne: $lineOne\n";
#get first value and increment with one
my @nrOfLearningLines=split(" ",$lineOne);
my $tmp=$nrOfLearningLines[0];
$tmp++;
print "new value:: ".$tmp."\n";
$lineOne=~s/$nrOfLearningLines[0]/$tmp/;
print "lineOne: $lineOne\n";

#replace first line using seek
open (FH, "+< $ARGV[1]") || die "can't open $filename: $!";
seek FH, 0, 0; # go back to the start of the file
printf FH $lineOne;
close FH;



print "\n$bitsread bits read in total, $telr padded bytes\n";
