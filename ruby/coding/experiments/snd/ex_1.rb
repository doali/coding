#!/usr/bin/env ruby

require 'ruby2d'

path_dir = '/home/blackpc/Music/Artist/TheRollingStones/Hot Rocks, 1964-1971 (1 of 2)'
path_song = '/home/blackpc/Music/Artist/TheRollingStones/Hot Rocks, 1964-1971 (1 of 2)/01 Time Is on My Side.mp3'

puts path_song

song = nil
tt = nil

timer = Thread.new {
    sleep 100
    puts "Finished"
}

t = Thread.new {
    songs = Dir.entries(path_dir).select { |f| File.file? File.join(path_dir, f) }    
    songs.each do
        alea_song = songs.sample
        puts alea_song
        song = path_dir + "/" + alea_song
        curr_song = Music.new(song)
            tt = Thread.new {
                sleep 5
                curr_song.stop
                puts "Finished"
            }
            curr_song.play
            tt.join
    end
}

t.join
timer.join

# Installation
# sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
# sudo gem install ruby2d
# Ressources
# https://www.ruby2d.com/learn/linux/
