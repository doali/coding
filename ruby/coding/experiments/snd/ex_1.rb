#!/usr/bin/env ruby

require 'ruby2d'

path_dir = '/home/blackpc/Music/Artist/TheRollingStones/Hot Rocks, 1964-1971 (1 of 2)'

song = nil
tt = nil

pool_th = []

timer_app = Thread.new {
    sleep 10
    puts "Finished"
}

songs_app = Thread.new {
    songs = Dir.entries(path_dir).select { |f| File.file? File.join(path_dir, f) }    
    songs.each do |song|
        p_song = path_dir + "/" + song
        curr_song = Music.new(p_song)
        timer_song = Thread.new {
            sleep 3                
            curr_song.stop                
        }
        puts song
        curr_song.play
        timer_song.join
    end
}

timer_app.join

# Installation
# sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
# sudo gem install ruby2d
# Ressources
# https://www.ruby2d.com/learn/linux/
