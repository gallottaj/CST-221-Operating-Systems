#!/bin/bash

# Joey Gallotta
# 11/15/2020
# CST-221

# Password Check

# flags weak (easily guessed) passwords
# password must be provided as an argument to the script

# To be considered acceptable, a password must meet the following minimum qualifications:
# I.  Minimum length of 8 characters
# II. Must contain at least one numeric character
# III.Must contain at least one of the following non-alphabetic characters: @, #, $, %, &, *, +, -, =

# Your script should print out which tests did not pass or print a clear message if all tests did pass.

 containsNumber="(\d)."
 containsCharacter="[@#\$%|&\*\+-=]."

 password=$1

# check number of arguments and throw error
  if [ $# -ne 1 ]; then
     echo "Error: Entry contains $# arguments."
     echo "Enter a single password as an argument."
  else
     echo "You entered: $password"
# check password length (8)
  length=${#password}
  if [ $length -lt 8 ]; then
     echo "Try again: Password length not met. Your password is $length characters. It must be at least 8 characters."
  exit
  fi
# check for numeric characters
  if ! [[ $password =~ $containsNumber ]]; then
     echo "Try again: Password must contain at least 1 numeric character."
  exit
  fi
# check for characters
  if ! [[ $password =~ $containsCharacter ]]; then
     echo "Try again: Password must contain at least one of the following characters:(@, #, $, %, &, *, +, -, =)"
  exit
  fi

  echo "All requirement me. Password is secure."
  fi
