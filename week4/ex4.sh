for i in {1..200} ; do
	echo "Enter Command: " 
	read command
	$command &
done
