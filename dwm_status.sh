#!/bin/bash

memory_usage() {
    mem_used=$(free -m | awk '/Mem:/ {print $3}')
    mem_total=$(free -m | awk '/Mem:/ {print $2}')
    echo "$mem_used/$mem_total""MB"
}

volume() {
    wpctl get-volume @DEFAULT_SINK@ | awk '{print int($3 * 100) "%"}'
}

date_time() {
    date "+%H:%M"
}

while true; do
    xsetroot -name "  $(memory_usage) |  $(volume) | $(date_time)"
    sleep 2
done
