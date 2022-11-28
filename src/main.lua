function love.load()
end

function love.update()
	mx, my = love.mouse.getPosition()
end

function love.draw()
	for x = 0, 150 do
		for y = 0, 150 do
			love.graphics.setColor(1/x*75, 1/y*75, 1/x*75)
			love.graphics.rectangle("fill", 50+x*2, 50+y*2, 1, 1)
		end
	end

	love.graphics.setColor(1,1,1)
	love.graphics.print('fps: ' .. love.timer.getFPS(), 10, 10)
	love.graphics.print('mx: ' .. mx, 10, 20)
	love.graphics.print('my: ' .. my, 10, 30)
end