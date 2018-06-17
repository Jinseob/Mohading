package com.portfolio.app.Controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;

import com.portfolio.app.Dao.CmmnDao;

@Controller
public class BoardController {
	private static final Logger logger = LoggerFactory.getLogger(BoardController.class);

	@Autowired
	private CmmnDao dao;
	
	@RequestMapping(value = "/b0010/b0010L.do")
	public String boardMain(ModelMap model, HttpServletRequest request, 
			HttpServletResponse response, HttpSession session) throws Exception{
		
		
		return "b0010/b0010L";
	}
}
