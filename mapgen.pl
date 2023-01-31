#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.21\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
    		print "2";
		}
		else {
			print "."; 
		}
	}
	print "\n"; 
}
