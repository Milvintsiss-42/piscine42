#!/bin/bash
id -Gn  $FT_USER | sed -e "s/ /,/g" | tr -d "\n"
