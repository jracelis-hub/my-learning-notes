#!/usr/bin/env bash

testing() 
{
	for i in {1..20}
	do
		$1 ${i}
	done
}

testing $1
