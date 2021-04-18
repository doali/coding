#!/usr/bin/env ruby

require 'ruby2d'

# Si un argument est passé en ligne de commande ARGV[0]
# Alors on joue depuis ce répertoire sinon => après le ||
path_dir = ARGV[0] || '/home/blackpc/Musique/Artist/TheRollingStones/Hot Rocks, 1964-1971 (1 of 2)'

# Vérification de l'existence du chemin
exit(1) if not File.directory?(path_dir) 

# Timer de l'application
timer_app = Thread.new {
    sleep 10
    puts "Finished"
}

# File d'exécution séparé
songs_app = Thread.new {
    # Tous les noms des fichiers contenus dans <path_dir>
    songs = Dir.entries(path_dir).select { |f| File.file? File.join(path_dir, f) }    
    
    # Pour chaque nom de fichier
    songs.each do |song|
        p_song = path_dir + "/" + song

        curr_song = Music.new(p_song) # <== ICI utilisation de ruby2d

        # Arme un timer pour écourter la chason
        timer_song = Thread.new {
            sleep 3                
            curr_song.stop                
        }
        puts song

        curr_song.play # <== ICI utilisation de ruby2d

        # Attente de la fin du thread timer_song
        # RM : si le thread timer_app termine avant 
        # => on quitte l'application
        timer_song.join
    end
}

timer_app.join

# Installation
# sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
# sudo gem install ruby2d
# Ressources
# https://www.ruby2d.com/learn/linux/
