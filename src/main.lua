function love.load()
	x = 100
	y = 100
	width = 100
	height = 100
end

function love.update()
	mx, my = love.mouse.getPosition()
end

function love.draw()
	love.graphics.setColor(1, 1, 1)
	
	if mx > x and mx < x + width and my > y and my < y + height then
		love.graphics.setColor(mx/800, my/600, (mx+my)/(800+600))

		if love.mouse.isDown(1) then
			x = mx - 50
			y = my - 50
		end
	end

	love.graphics.rectangle('fill', x, y, width, height)

	love.graphics.setColor(1, 1, 1)
	love.graphics.print('fps: ' .. love.timer.getFPS(), 10, 10)
	love.graphics.print('mx: ' .. mx, 10, 20)
	love.graphics.print('my: ' .. my, 10, 30)

end