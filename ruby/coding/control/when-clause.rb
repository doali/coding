#!/usr/bin/env ruby

# Ruby permits the use of ?
# for naming
def what_level?(student)
  level = student.level
  case level
  when 0
    puts "#{student} is a beginner student"
  when 1
    puts "#{student} is an intermediate student"
  when 2
    puts "#{student} is an advanced student"
  else
    puts "#{student} is a god"
  end
end

class Person
  attr_accessor :name
  attr_accessor :firstname

  def initialize(name, firstname)
    @name = name
    @firstname = firstname
  end

  def to_s
    "#{@firstname} #{name}"
  end
end

# Inheritance
class Student < Person
  # getter / setter
  attr_accessor :level

  # Default parameter defined
  def initialize(name, firstname, level=0)
    # super uses two arguments in order to match 
    # with it's parent 
    super(name, firstname)
    @level = level
  end

  def to_s
    # super (whithout parentheses is ok)
    # look for to_s in the parent class
    info = super
    "#{info} #{@level}"
  end
end

def test
  p = Person.new("Person", "Paul")
  puts p

  s1 = Student.new("Higher", "Tim", 2)
  s2 = Student.new("InTheMiddle", "Tom", 1)
  s3 = Student.new("Newbie", "Pam")
  s4 = Student.new("Master", "Karl9000", 9)

  list_student = []
  list_student << s1 << s2 << s3 << s4

  list_student.each do |student|
    puts student
    puts what_level?(student)
  end
end

def information
  puts "__FILE__ <= #{__FILE__}"
end

# Calling information method directly
information

# Trick as in python if __name__ == "__main__"
if __FILE__ == $0
  # No need to add parentheses
  information
  puts 
  test
end
