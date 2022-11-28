function love.load()
end

function love.update()
end

function love.draw()
	for x = 0, 150 do
		for y = 0, 150 do
			love.graphics.setColor(1/x*75, 1/y*75, 1/x*75)
			love.graphics.rectangle("fill", x*2, y*2, 1, 1)
		end
	end

	love.graphics.setColor(1,1,1)
	love.graphics.print('Text', 400, 400)
end