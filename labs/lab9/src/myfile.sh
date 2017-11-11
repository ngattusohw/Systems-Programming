function whicha(){
	for filename in `echo $PATH | tr ":" " "`;do
		if [ -e $filename/$* ];then
			echo $filename/$*
		fi
	done
}

whicha $*