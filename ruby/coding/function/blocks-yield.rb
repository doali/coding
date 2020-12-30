#!/usr/bin/env ruby

# ------------------------------------------------------------------------------
# http://rubyforadmins.com/blocks
# https://www.synbioz.com/blog/tech/block-proc-lambda-ruby
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# odd numbers
# Using block and select
l_odd = (1..10).select { |x| x.odd? }
puts "#{l_odd}"

# Here Documents
explanation = <<EOF
    select gets the first element in range 1..10 - the number 1
    it is passing this element to the block: |x| x.odd?
    in the block, the value of the element (number 1) is assigned to variable x
    1.odd? evaluates to true, so number 1 is included to the result
    the same continues to the next numbers
EOF

puts "#{explanation}"

# ------------------------------------------------------------------------------
# Common block usage
10.times do |x|
  puts "#{x} is odd? = #{x.odd?}"
end

# ------------------------------------------------------------------------------
# yield : evaluate the given block (only when it is given)
def say_something
  yield
end

say_something { puts "blocks are magic things" }
