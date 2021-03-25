echo "Welcome to OS String Reversal Program By Chiranjeet Under Dr. Deepa K."
read -p "Enter string: " var
copy=${var}

len=${#copy}
for((i=$len-1;i>=0;i--)); do rev="$rev${copy:$i:1}"; done

echo "Reversed String is: $rev"