.PHONY: clean All

All:
	@echo "----------Building project:[ rawsockets - Debug ]----------"
	$(MAKE) -f  "rawsockets.mk"
clean:
	@echo "----------Cleaning project:[ rawsockets - Debug ]----------"
	$(MAKE) -f  "rawsockets.mk" clean
