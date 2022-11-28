function love.load()
end

function love.update()
	mx, my = love.mouse.getPosition()
end

function love.draw()
	love.graphics.setColor(1, 1, 1)

	love.graphics.rectangle('fill', mx-50, my-50, 100, 100)

	
	love.graphics.circle('line', 100, 100, 20)


	love.graphics.setColor(1, 1, 1)
	love.graphics.print('fps: ' .. love.timer.getFPS(), 10, 10)
	love.graphics.print('mx: ' .. mx, 10, 20)
	love.graphics.print('my: ' .. my, 10, 30)

end